#include "order_book/order_book.hpp"
#include "order_book/order.hpp"
#include <string>

namespace order_book{
   void Orderbook::add_order(std::unique_ptr<Order> order) {
    Side side = order->side();
    double price = order->price();

    if (side == Side::Buy) {

        while (!m_asks.empty() && order->quantity() > 0) {

            // Best ask = lowest selling price.
            auto best_ask_it = m_asks.begin();
            double ask_price = best_ask_it->first;

            // Best seller is asking for more than we're willing to pay.
            if (ask_price > price) {
                break;
            }

            // All orders at this price level.
            auto& sells = best_ask_it->second;

            // Oldest order at this price.
            auto& sell = sells.front();

            if (sell->quantity() <= order->quantity()) {

                // The incoming buy can completely fill the sell order.
                std::uint64_t traded_quantity = sell->quantity();

                order->set_quantity(
                    order->quantity() - traded_quantity
                );

                // The sell order has been completely filled.
                sells.pop_front();

            } else {

                // The incoming buy is completely filled by
                // only part of the sell order.
                std::uint64_t traded_quantity = order->quantity();

                sell->set_quantity(
                    sell->quantity() - traded_quantity
                );

                order->set_quantity(0);
            }

            // No more orders at this price.
            if (sells.empty()) {
                m_asks.erase(best_ask_it);
            }
        }

        // Whatever remains becomes a resting bid.
        if (order->quantity() > 0) {
            m_bids[price].push_back(std::move(order));
        }

    } else if (side == Side::Sell) {

        while (!m_bids.empty() && order->quantity() > 0) {

            // Best bid = highest buying price.
            auto best_bid_it = m_bids.begin();
            double bid_price = best_bid_it->first;

            // Best buyer is offering less than we're willing to accept.
            if (bid_price < price) {
                break;
            }

            // All orders at this price level.
            auto& buys = best_bid_it->second;

            // Oldest order at this price.
            auto& buy = buys.front();

            if (buy->quantity() <= order->quantity()) {

                // Incoming sell can completely fill the buy order.
                std::uint64_t traded_quantity = buy->quantity();

                order->set_quantity(
                    order->quantity() - traded_quantity
                );

                // Buy order completely filled.
                buys.pop_front();

            } else {

                // Incoming sell is completely filled by
                // part of the buy order.
                std::uint64_t traded_quantity = order->quantity();

                buy->set_quantity(
                    buy->quantity() - traded_quantity
                );

                order->set_quantity(0);
            }

            // No more orders at this price.
            if (buys.empty()) {
                m_bids.erase(best_bid_it);
            }
        }

        // Whatever remains becomes a resting ask.
        if (order->quantity() > 0) {
            m_asks[price].push_back(std::move(order));
        }
    }
}
}



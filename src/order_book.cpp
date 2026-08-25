#include "order_book/order_book.hpp"
#include "order_book/order.hpp"

namespace order_book{
    void Orderbook::add_order(std::unique_ptr<Order> order){
        // side:Buy or sell , price 
        Side s = order -> side();
        double p = order->price(); 

        // 1st: buy order
        if (!m_asks.empty() && s == Side::Buy){
            // get least selling price
            double leastSellPrice = m_asks.rbegin()->first;
            //if least selling price is smaller or equal to buy, then match
            if (leastSellPrice <= p){
               auto sell = m_asks.find(leastSellPrice)->second;
                
            }   
        }

        while(!m_asks.empty() && s == Side::Buy){
            double leastSellPrice = m_asks.rbegin() -> first;
            
            if (leastSellPrice <= p){
                auto subSells = m_asks.find(leastSellPrice)->second;
                if(!subSells.empty()){
                    for(const auto& sell : subSells){
                        if (sell->quantity())
                    }
                }
            }
        }


    }
}



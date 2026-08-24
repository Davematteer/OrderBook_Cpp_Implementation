#include "order.hpp"
#include <deque>
#include <functional>
#include <map>
#include <memory>

namespace order_book {
  class Orderbook{
    public:
      void add_order(std::unique_ptr<Order> order);

    private:
      std::map<double,
        std::deque<std::unique_ptr<Order>>,
        std::greater<double>
          > m_bids;

      std::map<double,
        std::deque<std::unique_ptr<Order>>,
        std::less<double>
        > m_asks;
  };

}

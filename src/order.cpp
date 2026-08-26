#include <cstdint>
#include "order_book/order.hpp"

namespace order_book{
  Order::Order(std::uint64_t id, Side side, double price, std::uint64_t quantity):m_id(id), m_side(side), m_price(price), m_quantity(quantity){}

  std::uint64_t Order::id() const{
   return Order::m_id; 
  }

  Side Order::side() const{
    return Order::m_side;
  }

  double Order::price() const{
    return m_price;
  }

  std::uint64_t Order::quantity() const{
    return m_quantity;
  }

  void Order::set_quantity(std::uint64_t quantity){

  }

}// namespace order_book

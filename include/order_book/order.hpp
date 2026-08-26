#pragma once 


#include <cstdint>


namespace order_book{

  enum class Side{
    Buy,
    Sell
  };

  class Order{
    public:
      Order(std::uint64_t id, Side side, double price, std::uint64_t quantity);

      std::uint64_t id() const;
      Side side() const;
      double price() const;
      std::uint64_t quantity() const;

      void set_quantity(std::uint64_t quantity);

    private:
      std::uint64_t m_id;
      Side m_side;
      double m_price;
      std::uint64_t m_quantity;
  };
}

#pragma once

#include <cstdint>

class Pixel {
public:
  static constexpr int Size{1};

  Pixel() = default;
  Pixel(uint8_t red, uint8_t green, uint8_t blue)
      : red_{red}, green_{green}, blue_{blue} {}
  Pixel(const Pixel &other) = default;
  Pixel &operator=(const Pixel &other) = default;

  ~Pixel() = default;

  uint8_t &red() { return red_; }
  uint8_t &green() { return green_; }
  uint8_t &blue() { return blue_; }

  uint8_t red() const { return red_; }
  uint8_t green() const { return green_; }
  uint8_t blue() const { return blue_; }

  bool operator==(const Pixel &other) const {
    return this->red_ == other.red_ and this->green_ == other.green_ and
           this->blue_ == other.blue_;
  }

private:
  uint8_t red_{};
  uint8_t green_{};
  uint8_t blue_{};
};
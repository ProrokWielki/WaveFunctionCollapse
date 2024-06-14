#pragma once

class Position {
public:
  Position() = default;
  Position(int x, int y) : x_{x}, y_{y} {}

  int x() const { return x_; }
  int y() const { return y_; }

  int &x() { return x_; }
  int &y() { return y_; }

  friend Position operator+(Position lhs, const Position &rhs) {
    lhs.x_ += rhs.x_;
    lhs.y_ += rhs.y_;

    return lhs;
  }

private:
  int x_{};
  int y_{};
};
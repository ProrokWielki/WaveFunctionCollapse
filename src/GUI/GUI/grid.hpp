#pragma once

#include "GUI/drawable.hpp"
#include <type_traits>

template <typename T> class Grid : public Drawable {
public:
  constexpr static bool HAS_SUB_GRID{false};
  using CELL_TYPE = T;

  static_assert(std::is_base_of_v<Drawable, T>, "must be drawable");

  void add_element(Position position, std::shared_ptr<Drawable> element) {
    elements_.push_back({position, element});

    auto combined_offset = get_combined_width<T>();

    position.x() *= combined_offset;
    position.y() *= combined_offset;

    add_drawable(element, position);
  }

  template <typename H, bool E = H::HAS_SUB_GRID,
            typename std::enable_if<E, int>::type = 0>
  unsigned int get_combined_width() {
    return H::Size * get_combined_width<typename H::CELL_TYPE>();
  }

  template <typename H, bool E = H::HAS_SUB_GRID,
            typename std::enable_if<!E, int>::type = 0>
  unsigned int get_combined_width() {
    return H::Size;
  }

private:
  std::vector<std::pair<Position, std::shared_ptr<Drawable>>> elements_;
  unsigned int size_{};
};

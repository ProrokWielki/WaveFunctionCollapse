#include "GUI/drawing_engine.hpp"
#include "GUI/drawable.hpp"
#include "GUI/position.hpp"
#include <new>

void DrawingEngine::draw(const std::shared_ptr<Drawable> &drawable,
                         const Position &offset) {

  put_on_frame_buffer(drawable, offset);

  for (const auto &child_drawable : drawable->get_drawables()) {
    draw(child_drawable.second, offset + child_drawable.first);
  }
}

void DrawingEngine::put_on_frame_buffer(
    const std::shared_ptr<Drawable> &drawable, const Position &offset) {
  for (const auto &pixel : drawable->get_pixels())
    frame_buffer_->set_pixel(pixel.first + offset, pixel.second);
}

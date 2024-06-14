#pragma once

#include <memory>

#include "GUI/position.hpp"
#include "frame_buffer.hpp"

class Drawable;
class Position;

class DrawingEngine {
public:
  DrawingEngine(unsigned int width, unsigned int height)
      : frame_buffer_{std::make_shared<FrameBuffer>(width, height)} {}

  void draw(const std::shared_ptr<Drawable> &drawable,
            const Position &offset = {0, 0});

  virtual ~DrawingEngine() = default;

  virtual void show_frame_buffer() = 0;

protected:
  std::shared_ptr<FrameBuffer> frame_buffer_{};

private:
  void put_on_frame_buffer(const std::shared_ptr<Drawable> &drawable,
                           const Position &offset);
};
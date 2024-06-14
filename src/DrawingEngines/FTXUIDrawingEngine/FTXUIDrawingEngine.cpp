

#include <memory>

#include <ftxui/dom/canvas.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/dom/node.hpp>
#include <ftxui/screen/color.hpp>
#include <ftxui/screen/terminal.hpp>

#include "FTXUIDrawingEngine.hpp"

namespace {
constexpr int width_correction = 4;
constexpr int height_correction = 4;

} // namespace

ftxui::Color convert_color(const Pixel &pixel) {
  return {pixel.red(), pixel.green(), pixel.blue()};
}

FTXUIrawingEngine::FTXUIrawingEngine(unsigned int width, unsigned int height)
    : DrawingEngine(width, height),
      canvas_{std::make_shared<ftxui::Canvas>(width_correction * width,
                                              height_correction * height)},
      screen_{std::make_shared<ftxui::Screen>(ftxui::Screen::Create(
          ftxui::Dimension::Fixed(width_correction * width),
          ftxui::Dimension::Fixed(height_correction * height)))} {}

void FTXUIrawingEngine::show_frame_buffer() {
  for (auto y = 0; y < frame_buffer_->get_height(); ++y) {
    for (auto x = 0; x < frame_buffer_->get_width(); ++x) {
      put_pixel(x, y, frame_buffer_->get_frame_buffer()[y][x]);
    }
  }

  auto document = canvas(canvas_.get()) | ftxui::border;

  auto screen = ftxui::Screen::Create(ftxui::Dimension::Fit(document));
  ftxui::Render(screen, document);
  screen.Print();

  //   auto document = canvas(*canvas_);

  //   Render(*screen_, canvas(*canvas_));
  //   screen_->Print();
}

void FTXUIrawingEngine::put_pixel(int x, int y, const Pixel &pixel) {
  for (auto y_mul = 0; y_mul < height_correction; ++y_mul) {
    for (auto x_mul = 0; x_mul < width_correction; ++x_mul) {
      canvas_->DrawBlock(x * width_correction + x_mul,
                         y * height_correction + y_mul, true,
                         convert_color(pixel));
    }
  }
}

FTXUIrawingEngine::~FTXUIrawingEngine() = default;
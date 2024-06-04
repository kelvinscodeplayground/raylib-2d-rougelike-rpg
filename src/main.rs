use raylib::prelude::*;

fn main() {
    let (mut rl, thread) = raylib::init()
        .title("2D Rougelike Demo")
        .size(1280, 720)
        .build();
    rl.set_target_fps(60);

    while !rl.window_should_close() {
        let mut brush = rl.begin_drawing(&thread);
        brush.clear_background(Color::WHITE);
    }
}

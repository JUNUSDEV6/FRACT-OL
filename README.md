Fractal Renderer
Overview

Welcome to the Fractal Renderer project! This is a simple program written in C that allows you to visualize and explore the beauty of fractals, specifically the Mandelbrot set and the Julia set. The application utilizes the MiniLibX library for graphics rendering.

Table of Contents

    Getting Started
    Usage
    Features
    Development Process
    Code Highlights
    Contributing
    License

Getting Started

To get started with the Fractal Renderer, follow these steps:

    Clone the repository to your local machine.
    Ensure you have the MiniLibX library installed.
    Compile the project using the provided Makefile.
    Run the executable with appropriate command-line arguments.

Usage

The Fractal Renderer supports two types of fractals: Mandelbrot and Julia. You can specify the fractal type and additional parameters (in the case of Julia) through command-line arguments.

Example Commands:

    Render Mandelbrot set:

    bash

./fractal mandelbrot

Render Julia set:

bash

./fractal julia <real_part> <imaginary_part>

Features

    Visualizes the Mandelbrot set and Julia set.
    Allows dynamic exploration through zooming and panning.
    Supports real-time rendering and user interaction.

Development Process
Initialization and Window Setup

The project begins with the initialization of the fractal structure and the MiniLibX window. Error handling is incorporated to manage potential issues during initialization.

c

int main(int argc, char **argv) {
    // ...
    fractal_init(&fractal);
    fractal_render(&fractal);
    event(&fractal);
    mlx_loop(fractal.mlx_connection);
    // ...
}

Fractal Rendering

The heart of the application lies in the rendering of fractals. The fractal_render function iterates over each pixel, calculates the corresponding complex number, and determines the color based on the escape value.

c

void fractal_render(t_fractal *fractal) {
    // ...
    while (++y < HEIGHT) {
        while (++x < WIDTH) {
            handle_pixels(x, y, fractal);
        }
    }
    mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->img.img_ptr, 0, 0);
}

User Interaction

The program allows user interaction through keyboard and mouse events. Key presses control movement and zoom, while mouse wheel actions adjust the zoom level.

c

void event(t_fractal *fractal) {
    mlx_hook(fractal->mlx_window, 2, 0, key_press, fractal);
    mlx_hook(fractal->mlx_window, 17, 0, ft_close, fractal);
    mlx_hook(fractal->mlx_window, 4, 0, mouse_handle, fractal);
}

Code Highlights
Command-Line Argument Parsing

c

if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)) 
    || (argc == 4 && !ft_strncmp(argv[1], "julia", 5))) {
    // ...
} else {
    putstr_fd("ERROR INPUT\n", 2);
    exit(1);
}

Complex Number Operations

c

t_complex sum_complex(t_complex z1, t_complex z2) {
    t_complex result;
    result.x = z1.x + z2.x;
    result.y = z1.y + z2.y;
    return result;
}

t_complex square_complex(t_complex z) {
    t_complex result;
    result.x = (z.x * z.x) - (z.y * z.y);
    result.y = 2 * z.x * z.y;
    return result;
}

Contributing

If you'd like to contribute to the project, feel free to fork the repository and submit pull requests. Any contributions are welcome!
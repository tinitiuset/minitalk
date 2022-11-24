cmake_minimum_required(VERSION 3.19)
project(minitalk C)

set(CMAKE_C_STANDARD 99)

include_directories(libft_extra)

add_executable(minitalk
        server.c
        libft_extra/libft/ft_atoi.c
        libft_extra/libft/ft_isdigit.c
        libft_extra/ft_printf/ft_printf.c
        libft_extra/ft_printf/ft_putnbr_base.c
        libft_extra/ft_printf/ft_long_itoa.c
        libft_extra/libft/ft_strlen.c
        )
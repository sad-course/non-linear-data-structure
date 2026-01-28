import pygame
from settings import *
from grid import *
from ui import draw
from algorithms.astar import astar
from algorithms.greedy import greedy

pygame.init()
WIN = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Pathfinding - A* vs Guloso")

def main():
    current_mode = "WALL"

    grid = make_grid(ROWS, WIDTH)
    start = end = None
    algorithm = "A*"

    run = True
    while run:
        draw(WIN, grid, ROWS, WIDTH)

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                run = False

            if pygame.mouse.get_pressed()[0]:
                pos = pygame.mouse.get_pos()
                row = pos[1] // (WIDTH // ROWS)
                col = pos[0] // (WIDTH // ROWS)
                node = grid[row][col]


                if current_mode == "START":
                    if start:
                        start.color = WHITE
                    start = node
                    node.color = YELLOW

                elif current_mode == "END":
                    if end:
                        end.color = WHITE
                    end = node
                    node.color = RED

                elif current_mode == "WALL":
                    if node != start and node != end:
                        node.color = BLACK
            
            if pygame.mouse.get_pressed()[2]:
                pos = pygame.mouse.get_pos()
                row = pos[1] // (WIDTH // ROWS)
                col = pos[0] // (WIDTH // ROWS)
                node = grid[row][col]
                node.color = WHITE

                if node == start:
                    start = None
                if node == end:
                    end = None
            
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_SPACE and start and end:
                    for row in grid:
                        for node in row:
                            node.update_neighbors(grid)
                    if algorithm == "A*":
                        astar(lambda: draw(WIN, grid, ROWS, WIDTH), grid, start, end)
                    else:
                        greedy(lambda: draw(WIN, grid, ROWS, WIDTH), grid, start, end)

                if event.key == pygame.K_s:
                    current_mode = "START"


                if event.key == pygame.K_e:
                    current_mode = "END"

                if event.key == pygame.K_w:
                    current_mode = "WALL"

                if event.key == pygame.K_TAB:
                    algorithm = "GREEDY" if algorithm == "A*" else "A*"

                if event.key == pygame.K_c:
                    grid = make_grid(ROWS, WIDTH)
                    start = end = None

    pygame.quit()

main()

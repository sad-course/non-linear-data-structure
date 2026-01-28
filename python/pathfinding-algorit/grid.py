import pygame
from settings import *

class Node:
    def __init__(self, row, col, width):
        self.row = row
        self.col = col
        self.x = col * width
        self.y = row * width
        self.color = WHITE
        self.neighbors = []
        self.width = width

    def get_pos(self):
        return self.row, self.col

    def is_wall(self):
        return self.color == BLACK

    def draw(self, win):
        pygame.draw.rect(win, self.color,
                         (self.x, self.y, self.width, self.width))

    def update_neighbors(self, grid):
        self.neighbors = []
        directions = [(1,0),(-1,0),(0,1),(0,-1)]
        for dr, dc in directions:
            r, c = self.row + dr, self.col + dc
            if 0 <= r < len(grid) and 0 <= c < len(grid):
                if not grid[r][c].is_wall():
                    self.neighbors.append(grid[r][c])

def make_grid(rows, width):
    grid = []
    gap = width // rows
    for i in range(rows):
        grid.append([])
        for j in range(rows):
            grid[i].append(Node(i, j, gap))
    return grid

def draw_grid(win, rows, width):
    gap = width // rows
    for i in range(rows):
        pygame.draw.line(win, GREY, (0, i * gap), (width, i * gap))
        pygame.draw.line(win, GREY, (i * gap, 0), (i * gap, width))

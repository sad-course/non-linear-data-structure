import pygame
from queue import PriorityQueue
from settings import *
import math

def euclidean(p1, p2):
    x1, y1 = p1
    x2, y2 = p2
    return math.sqrt((x1 - x2)**2 + (y1 - y2)**2)

def greedy(draw, grid, start, end):
    open_set = PriorityQueue()
    open_set.put((0, start))
    came_from = {}
    visited = set()

    while not open_set.empty():
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()

        current = open_set.get()[1]

        if current == end:
            reconstruct_path(came_from, end, draw)
            return True

        visited.add(current)

        for neighbor in current.neighbors:
            if neighbor not in visited and not neighbor.is_wall():
                came_from[neighbor] = current
                priority = euclidean(neighbor.get_pos(), end.get_pos())
                open_set.put((priority, neighbor))
                neighbor.color = GREEN

        draw()
        if current != start:
            current.color = PURPLE

    return False

def reconstruct_path(came_from, current, draw):
    while current in came_from:
        current = came_from[current]
        current.color = BLUE
        draw()

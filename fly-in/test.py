import pygame


class Rettangolo:
    def __init__(self, coord: tuple[int, int] = (960, 540), screen_size: tuple[int, int] = (1920, 1080)):
        self.x = coord[0]
        self.y = coord[1]
        self.screen_size = screen_size
        self.speed_x = 0
        self.speed_y = 0
        self.rect = pygame.rect.Rect(0, 0, 50, 50)
        self.rect.center = (self.x, self.y)

    def set_speed(self, hor_speed: int, vert_speed: int):
        self.speed_x = hor_speed
        self.speed_y = vert_speed
        self.rect.center = (self.x, self.y)

    def move(self):
        self.x += self.speed_x
        self.y += self.speed_y
        if self.x < 0:
            self.x = self.screen_size[0]
        if self.y < 0:
            self.y = self.screen_size[1]
        if self.x > self.screen_size[0]:
            self.x = 0
        if self.y > self.screen_size[1]:
            self.y = 0
        self.rect.center = (self.x, self.y)


def main():
    pygame.init()
    display = pygame.display.set_mode((1920, 1080))
    clock = pygame.time.Clock()
    rettangolo = Rettangolo()
    running = True
    dt = 0

    while running:
        display.fill((230, 210, 220))
        pygame.draw.rect(display, (150, 110, 130), rettangolo.rect)
        rettangolo.move()
        pygame.display.flip()
        # tempo_passato += dt
        # tempo_totale = 200
        # progresso = tempo_passato / tempo_totale
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_q:
                    running = False
                if event.key == pygame.K_UP:
                    rettangolo.set_speed(0, -2)
                if event.key == pygame.K_DOWN:
                    rettangolo.set_speed(0, 2)
                if event.key == pygame.K_RIGHT:
                    rettangolo.set_speed(2, 0)
                if event.key == pygame.K_LEFT:
                    rettangolo.set_speed(-2, 0)
            if event.type == pygame.KEYUP:
                if event.key == pygame.K_UP:
                    rettangolo.set_speed(0, 0)
                if event.key == pygame.K_DOWN:
                    rettangolo.set_speed(0, 0)
                if event.key == pygame.K_RIGHT:
                    rettangolo.set_speed(0, 0)
                if event.key == pygame.K_LEFT:
                    rettangolo.set_speed(0, 0)

        clock.tick(120)
    pygame.quit()


if __name__ == "__main__":
    main()

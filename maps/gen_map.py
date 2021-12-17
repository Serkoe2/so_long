from random import choice, randint
from os import path

STONES = ["Agate", "Amethyst", "Aquamarine", "Aventurine", "Emerald", "Diamond",
        "Turquoise", "Pearl", "Coral", "Jade", "Moonstone", "Malachite", "Opal",
        "Ruby", "Sapphire", "Topaz", "Nephrite", "Onyx", "Obsidian", "Tourmaline",
        "Quartz", "Fluorite", "Citrine", "Amber", "Jasper", "Zircon"]
BODIES = ["Planet", "Asteroid", "Black hole", "Comet", "Constellation", "Galaxy",
        "Meteorite", "Orbit", "Star", "Satellite", "Space", "Sun"]

class Map_Generator:
    def __init__(self):
        self.width = 20
        self.height = 15
        self.map = []
        self.menu()

    def menu(self):
        print("Choose:\n1. Gen correct map\n2. Gen uncorrect map\n0. Exit")
        while True:
            ch = input()
            if (ch == '1'):
                self.gen_correct()
                self.save_map()
                return
            elif (ch == '0'):
                return

    def gen_correct(self):
        symbols = list("0001CEP")
        self.map.append(['1' for i in range(self.width)])
        for i in range(self.height - 2):
            temp = []
            temp.append('1')
            for j in range(self.width - 2):
                ch = choice(symbols)#choice(''.join(symbols))
                temp.append(ch)
                if (ch in "EP"):
                    symbols.pop(symbols.index(ch))
            temp.append('1')
            self.map.append(temp)
        if ('E' in symbols):
            while True:
                y,x = randint(1, self.height - 2), randint(1, self.width - 2)
                if (self.map[y][x] != 'P'):
                    self.map[y][x] = 'E'
                    break
        if ('P' in symbols):
            while True:
                y,x = randint(1, self.height - 2), randint(1, self.width - 2)
                if (self.map[y][x] != 'E'):
                    self.map[y][x] = 'P'
                    break
        self.map.append(['1' for i in range(self.width)])

    def get_name(self):
        tries = 0
        while True:
            if (tries > 5):
                name = "{}-{}{}.ber".format(choice(STONES), choice(BODIES), randint(1, 1000))
            else:
                name = "{}-{}.ber".format(choice(STONES), choice(BODIES))
            if (not path.exists(name)):
                return name
            tries += 1

    def save_map(self):
        save = [''.join(x) for x in self.map]
        save = '\n'.join(save)
        print(save)
        with open(self.get_name(), 'w') as f:
            f.write(save)

if __name__ == '__main__':
    mg = Map_Generator()
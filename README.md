This project is inspired by the world-famous eponymous 90’s game, which was the first FPS ever. In fact, it heavily relies on ray-casting. The goal is to make a dynamic view inside a maze. This code is written in accordance to the Norm v3, and has been graded 105/100.

**USAGE:**<br>
In order to run the game with default maps and textures, just execute make with  `make run` inside the game folder. This will compile both minilibx and libft. It is possible to change map by editing the path contained in the variable `MAP` of the Makefile.

**OTHER:**
The makefile contains other useful rules:
  * `norme` checks for norme errors inside all files except for the ones contained in the minilibx folder
  * `leaks` runs the game and shows remaining leaks at end of the execution
  * `save` takes a screenshot at the first frame of the game.

![Screenshot](https://github.com/Plachido/42/blob/5fc2224fea84efbf8c718bd5731676314a3c8bb9/cub3d/Screenshot.png)

# sineWaveCalc
This makes waves using c and opengl within linux

<h2>Remember, OpenGL grid values max out at one. so, point (0,0) is the middle of the screen,
    point (1,1) is the top right, 
    point (-1,1) is top left,
    point (-1,-1) is the bottom left
    point (1, -1) is the bottom right</h2>
  These are important if you want to tweak the program to solve math equations.

This Repo contains a make file so that you can compile the code. Be sure to enter the command 'sudo chmod 755 make.sh'
so that the permissions will be corrected then execute the binary with 'sudo ./run'. It must be run as root because of the OpenGL calls. Your GPU, in most cases, will reqire admin access.

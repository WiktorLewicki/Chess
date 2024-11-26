Work time: 18h

Presentation: https://youtu.be/sEf40HceMeU

I am the sole author of the entire code. Wiktor Lewicki.

The bot and the engine are located in the files bot.cpp and silnik.cpp.

The graphical interface was written in Qt 6.7.

For Windows: To play the game with a graphical interface, you need to go to the GRA_WIN/Files folder and run the Szachy.exe file.

For Linux: To play the game, install the required packages listed in packets.txt and use the following command to compile and run the game: bash build.sh

As for the bot, it plays fairly well. It's a minmax algorithm with alpha-beta pruning with variable depth. However, it's known that it's difficult to write a very strong chess bot, especially on your own chess engine.
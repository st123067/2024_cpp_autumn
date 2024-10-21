# Название программы
program: Source.o Source1.o
	 g++ Source.o Source1.o -o text_editor

# Компиляция Source.cpp
Source.o: Source.cpp Header.h
	 g++ -c Source.cpp

# Компиляция Source1.cpp
Source1.o: Source1.cpp Header.h
	 g++ -c Source1.cpp

# Очистка скомпилированных файлов
clean:
	 rm -f text_editor *.o

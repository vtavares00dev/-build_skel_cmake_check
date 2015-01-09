INCLUDE_DIRECTORIES( . )
ADD_EXECUTABLE(To_Do_List   main.c todo.c)
ADD_LIBRARY(todo_lib todo.c)

class StringGame

  def initialize()
  end

  def print (texto)
    @texto = texto
    puts texto
  end
  
  def print_int (int)
     puts int
  end
  
  def dream (time)
      sleep(time)
  end
  
  def hidden_cursor (confimation)
        case confirmation
  when 1
    print "\e[?25l"
  when 0
    print "\e[?25h"
  else
    puts "no hidden_cursor"
  end
  def attibute_text (color)
       
       case color
  when 0 # negro
    print "\e[30m"
    print "\e[0m"
  when 1 # rojo
    print "\e[31m"
    print "\e[0m"
  when 2 # verde
    print "\e[32m"
    print "\e[0m"
  when 3 # amarillo
    print "\e[33m"
    print "\e[0m"
  when 4 # azul
    print "\e[34m"
    print "\e[0m"
  when 5 # morado
    print "\e[35m"
    print "\e[0m"
  when 6 # cyan
    print "\e[36m"
    print "\e[0m"
  when 7 # blanco
    print "\e[37m"
    print "\e[0m"
  end
  end
  
  def goto_xy (x,y)
       print "\e[#{y};#{x}H"
  end
  
  def center_text (text)
       rows, columns = `stty size`.split.map(&:to_i) # obtiene el número de filas y columnas de la terminal
       x = (columns - text.length) / 2 # calcula la columna en la que se debe mover el cursor
       print "\e[#{x + 1}G" # mueve el cursor a la columna adecuada
       puts text
  end
  
  def exit_program
       abort
  end
  
  def read_input (var)
       var = gets.chomp 
       return var
  end
  
  def genere_random_abc
       random = Random.new # crea una nueva instancia de la clase Random
       10.times do # repite el código 10 veces
       letter = (random.rand(26) + 65).chr # genera un número aleatorio entre 0 y 25 y lo convierte en una letra del abecedario
       puts letter # imprime la letra
  end
  
  def read_key
      key = STDIN.getch
      return key
  end
  
  def read_line
      gets()
  end
  
  def compare_str (str_1,str_2)
       if str_1 == str_2
           return true
       end
           return false
  end
  
  def genere_random_int
       random = Random.new # crea una nueva instancia de la clase Random
       number = random.rand(10) # genera un número aleatorio entre 0 y 9
       return number
  end
  
  def dupli_text (text, times, newline)
       full_text = "" # variable para almacenar el texto completo
  times.times do # repite el código "times" veces
    full_text << text # añade el texto a la variable "full_text"
    full_text << "\n" if newline # añade un salto de línea si "newline" es "true"
  end
  puts full_text # imprime el texto completo
  end
  
  def _clrscr
      if RUBY_PLATFORM =~ /win32|win64|\.NET|windows|cygwin|mingw32/i # si se está ejecutando en Windows
          system("cls") # ejecuta el comando "cls" para limpiar la pantalla
     else # si se está ejecutando en otro sistema operativo
         system("clear") # ejecuta el comando "clear" para limpiar la pantalla
      end
  end

end

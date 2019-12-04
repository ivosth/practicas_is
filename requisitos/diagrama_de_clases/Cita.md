### NOMBRE DE LA CLASE:  
Cita

### DESCRIPCIÓN:
La clase representa las citas que tiene cada paciente, cada cita tiene sus datos propios

### ATRIBUTOS:
- fullname	(Cadena de caracteres):	 Nombre y apellidos del paciente
- date (Cadena de caracteres): Fecha de la cita
- start	(Cadena de caracteres):	 Hora de inicio de la cita
- end	(Cadena de caracteres):	 Hora de finalizacion de la cita
- description	(Cadena de caracteres):	 Motivo de la cita

### ACCIONES:
- init: Constructor de la clase paciente, que inicializa todas las variables imprescindibles de la misma
- todays_dates: Se muestran por pantalla todas las citas cuya fecha (hora de inicio y finalización) 
- corresponda al día de hoy
- add_date: Añade una cita a un paciente
- modify_date: Modifica algún parámetro de un objeto del tipo cita
- delete_date: Elimina de la base de datos un objeto del tipo cita
- show_dates: Muestra por pantalla las citas de un paciente concreto 

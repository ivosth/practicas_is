NOMBRE DE LA CLASE: Paciente

DESCRIPCIÓN: 
La clase representa a un único paciente de la consulta, y contiene sus datos personales

ATRIBUTOS: 
fullname	Cadena de caracteres	 Nombre y apellidos del paciente
address	Cadena de caracteres	 Dirección del paciente
phone		Cadena de caracteres	 Número de teléfono del paciente
birthdate	Cadena de caracteres	 Fecha de nacimiento del paciente
insurance	Cadena de caracteres	 Indica si el paciente posee un seguro médico particular o por mutua 

ACCIONES:
-init: Constructor de la clase paciente, que inicializa todas las variables imprescindibles de la misma.
-add_patient: Añade un nuevo objeto del tipo paciente a la base de datos.
-modify_patient: Modifica algún atributo de un paciente
-delete_patient: Borra de la base de datos un objeto del tipo paciente
-find_patient: Busca un objeto del tipo paciente mediante su nombre y apellidos.

## Añadir nuevo paciente

**ID**: 08 **Descripción**: Se introduce el nombre y apellidos del usuario que se busca y el sistema lo muestra.

**Actores principales**: Secretario 

**Precondiciones**:
* Ninguna

**Flujo principal**:
1. El secretario desea añadir  nuevo paciente.
1. El secretario abre el cuadro de diálogo de búsqueda en el menú principal.
1. El sistema comprueba que no existe un paciente registrado con el mismo nombre y apellidos
1. El sistema pide los datos personales del paciente a añadir: nombre y apellidos, domicilio, número de teléfono, fecha de nacimiento y seguro público/privado.
1. El secretario introduce los datos personales del paciente: nombre y apellidos, domicilio, número de teléfono, fecha de nacimiento y seguro público/privado.
1. Se muestra al secretario si los datos se han introducido correctamente.


**Postcondiciones**:

* Ninguna.

**Flujos alternativos**:
3.a. Si el paciente existe se notificará y no dejará introducirlo.  
5.a. Si los datos del paciente no se han introducido correctamente, no se introducirán y se mostrará un mensaje de error.

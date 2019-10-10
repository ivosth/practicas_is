## Consultar datos personales de un paciente

**ID**:07 **Descripción**: El secretario inserta el nombre y apellido de un paciente para ver sus datos personales  

**Actor principal**: Secretario
**Actor secundario**: Paciente

**Precondiciones**: Ninguna

**Flujo principal**:
1. El administrador desea conocer los datos personales de un paciente concreto
2. El secretario abre el cuadro de diálogo de búsqueda en el menú principal con el caso de uso de buscar paciente
3. Una vez encontrado el paciente, el sistema muestra por pantalla los datos personales del paciente

**Postcondiciones**:  Ninguna

**Flujos alternativos**:  
3.a Si el usuario no está registrado como cliente, se mostrará un mensaje que lo indique.

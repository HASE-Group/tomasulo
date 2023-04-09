
t_reg_args Decode_Register(char *Input_Reg)
{
	t_reg_args new_reg;
	if ((Input_Reg[0]=='F')
	 && (Input_Reg[1]=='L')
	 && (Input_Reg[2]=='B'))
	  {
	   new_reg.type='B';                   // Floating-point Buffer
	   new_reg.number=atoi(Input_Reg+3);
          } 
	else if (Input_Reg[0]=='F')
	  {
    	   new_reg.type='F';                   // Floating-point Register
           new_reg.number=atoi(Input_Reg+1);
          }
	else
	  {
	   new_reg.type='S';                  // Store Data Buffer
	   new_reg.number=atoi(Input_Reg+3);
          }
    return new_reg;
}

int Decode_AU_Op(t_cdb_instrn_set instr)
{
    switch(instr.function) {
    case t_cdb_instrn_set::ADD: case t_cdb_instrn_set::SUB: 
    case t_cdb_instrn_set::MUL: case t_cdb_instrn_set::DIV:
	return 1;
    default:
	return 0;
    }
}

int is_a_function(t_cdb_instrn_set instr)
{
    switch(instr.function) {
    case t_cdb_instrn_set::ADDRR: case t_cdb_instrn_set::ADDRS: 
    case t_cdb_instrn_set::SUBRR: case t_cdb_instrn_set::SUBRS: 
    case t_cdb_instrn_set::MULRR: case t_cdb_instrn_set::MULRS: 
    case t_cdb_instrn_set::DIVRR: case t_cdb_instrn_set::DIVRS:
    case t_cdb_instrn_set::LOAD: case t_cdb_instrn_set::STORE: 
    case t_cdb_instrn_set::STOP:
	return 1;
    default:
	return 0;
    }
}


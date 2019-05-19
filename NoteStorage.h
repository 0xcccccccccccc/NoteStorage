//20190518 PythonMa
#ifndef _NOTESORTAGE_H_
#define _NOTESORTAGE_H_
#include "EEPROM.h"
class Note
{
  public:
  int len,freq;
    Note(int len,int freq)
    {
      this->len=len;
      this->freq=freq; 
     }
     Note()
    {
    }

};
union DATA{
  int a;
  byte b[2];
};
void EEPROM_WRITE_INT(int addr,int data)
{
  int base=addr*2;
  DATA d;
  d.a=data;
  EEPROM.write(base,d.b[0]);
  EEPROM.write(base+1,d.b[1]);
}
int EEPROM_READ_INT(int addr)
{
  int base=addr*2;
  DATA d;
  d.b[0]=EEPROM.read(base);
  d.b[1]=EEPROM.read(base+1);
  return d.a;
}
void storeNote(Note note,int pos)
{
  EEPROM_WRITE_INT(pos*2,note.len);
  EEPROM_WRITE_INT(pos*2+1,note.freq);
}
Note readNote(int pos)
{
  Note note;
  note.len=EEPROM_READ_INT(pos*2);
  note.freq=EEPROM_READ_INT(pos*2+1);
  return note;
}
Note createNote(int len,int freq)
{
	return *(new Note(len,freq));
}
void format()
{
	for (int i = 0 ; i < EEPROM.length() ; i++) {
    EEPROM.write(i, 0);
  }
}
#endif

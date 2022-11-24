#include "framework.h"
//#include "acme/_start.h"
#include "acme/_.h"
//#include "acme/filesystem/file/file.h"
#include "id3/readers.h"
//#include "acme/_defer.h"


ID3_IStreamReader::ID3_IStreamReader(::file::file* reader) : m_pfile(reader) { ; }
   ID3_IStreamReader::~ID3_IStreamReader() { ; }
   void ID3_IStreamReader::close() { ; }

   ID3_Reader::int_type ID3_IStreamReader::peekChar() { auto b = m_pfile->peek_byte(); return m_pfile->is_end_of_file() ? EOF : b; }

   /** Read up to \c len chars into buf and advance the internal position
    ** accordingly.  Returns the number of characters read into buf.
    **/
   ID3_Reader::size_type ID3_IStreamReader::readChars(char buf[], size_type len)
   {
      return this->readChars(reinterpret_cast<uchar*>(buf), len);
   }
   ID3_Reader::size_type ID3_IStreamReader::readChars(char_type buf[], size_type len)
   {
      return (size_type)m_pfile->read((char*)buf, len);
   }

   ID3_Reader::pos_type ID3_IStreamReader::getBeg() { return 0; }
   ID3_Reader::pos_type ID3_IStreamReader::getCur() { return (pos_type)m_pfile->get_position(); }
   ID3_Reader::pos_type ID3_IStreamReader::getEnd() { return (pos_type)m_pfile->get_size(); }

   /** Set the value of the internal position for reading.
    **/
   ID3_Reader::pos_type ID3_IStreamReader::setCur(pos_type pos) { m_pfile->set_position(pos); return pos; }


   ID3_IFStreamReader::ID3_IFStreamReader(::file::file* reader)
      : ID3_IStreamReader(reader) { }

   void ID3_IFStreamReader::close()
   {
      m_pfile->close();
   }




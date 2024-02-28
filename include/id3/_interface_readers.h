// Created by camilo on 2023-01-06 20:47 <3ThomasBorregaardSorensen!!
#pragma once


namespace id3lib
{


   class reader
   {
   public:


      virtual unsigned char peek_byte() = 0;
      virtual bool is_end_of_file() = 0;
      virtual size_t read(char * pch, size_t len) = 0;
      virtual size_t get_position() = 0;
      virtual size_t size() = 0;
      virtual void set_position(size_t) = 0;
      virtual void close() = 0;


   };



} // namespace id3lib




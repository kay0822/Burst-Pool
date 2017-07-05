


namespace IDB {
 class sqlBetweenUInt: public Where {
  private:
   std::string col;
   unsigned long int min, max;

  public:
   sqlBetweenUInt(std::string init_col, unsigned long int min_value, unsigned long int max_value);
   std::string toString();


    unsigned int bind(sql::PreparedStatement *pstmt, unsigned int bind_offset);

 };
}

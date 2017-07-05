


namespace IDB {
 class sqlBetweenUInt64: public Where {
  private:
   std::string col;
   unsigned long long int min, max;

  public:
   sqlBetweenUInt64(std::string init_col, unsigned long long int min_value, unsigned long long int max_value);
   std::string toString();


    unsigned int bind(sql::PreparedStatement *pstmt, unsigned int bind_offset);

 };
}

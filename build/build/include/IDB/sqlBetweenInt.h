


namespace IDB {
 class sqlBetweenInt: public Where {
  private:
   std::string col;
   long int min, max;

  public:
   sqlBetweenInt(std::string init_col, long int min_value, long int max_value);
   std::string toString();


    unsigned int bind(sql::PreparedStatement *pstmt, unsigned int bind_offset);

 };
}

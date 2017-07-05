


namespace IDB {
 class sqlBetweenDouble: public Where {
  private:
   std::string col;
   double min, max;

  public:
   sqlBetweenDouble(std::string init_col, double min_value, double max_value);
   std::string toString();


    unsigned int bind(sql::PreparedStatement *pstmt, unsigned int bind_offset);

 };
}

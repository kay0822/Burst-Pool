


namespace IDB {
 class sqlBetweenString: public Where {
  private:
   std::string col;
   std::string min, max;

  public:
   sqlBetweenString(std::string init_col, std::string min_value, std::string max_value);
   std::string toString();


    unsigned int bind(sql::PreparedStatement *pstmt, unsigned int bind_offset);

 };
}

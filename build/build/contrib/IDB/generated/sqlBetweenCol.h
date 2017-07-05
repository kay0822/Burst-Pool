


namespace IDB {
 class sqlBetweenCol: public Where {
  private:
   std::string col;
   std::string min, max;

  public:
   sqlBetweenCol(std::string init_col, std::string min_value, std::string max_value);
   std::string toString();




 };
}

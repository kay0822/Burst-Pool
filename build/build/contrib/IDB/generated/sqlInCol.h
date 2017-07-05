
namespace IDB {
 class sqlInCol: public Where {
  private:
   std::string col;
   std::vector<std::string> values;

  public:
   sqlInCol(std::string init_col, std::vector<std::string> *init_values);
   sqlInCol(std::string init_col, std::list<std::string> *init_values);
   std::string toString();




 };
}

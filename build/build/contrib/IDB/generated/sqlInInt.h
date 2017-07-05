
namespace IDB {
 class sqlInInt: public Where {
  private:
   std::string col;
   std::vector<long int> values;

  public:
   sqlInInt(std::string init_col, std::vector<long int> *init_values);
   sqlInInt(std::string init_col, std::list<long int> *init_values);
   std::string toString();


    unsigned int bind(sql::PreparedStatement *pstmt, unsigned int bind_offset);

 };
}

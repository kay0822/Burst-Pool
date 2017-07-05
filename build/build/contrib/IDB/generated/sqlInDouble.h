
namespace IDB {
 class sqlInDouble: public Where {
  private:
   std::string col;
   std::vector<double> values;

  public:
   sqlInDouble(std::string init_col, std::vector<double> *init_values);
   sqlInDouble(std::string init_col, std::list<double> *init_values);
   std::string toString();


    unsigned int bind(sql::PreparedStatement *pstmt, unsigned int bind_offset);

 };
}

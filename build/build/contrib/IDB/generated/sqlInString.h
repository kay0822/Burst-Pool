
namespace IDB {
 class sqlInString: public Where {
  private:
   std::string col;
   std::vector<std::string> values;

  public:
   sqlInString(std::string init_col, std::vector<std::string> *init_values);
   sqlInString(std::string init_col, std::list<std::string> *init_values);
   std::string toString();


    unsigned int bind(sql::PreparedStatement *pstmt, unsigned int bind_offset);

 };
}

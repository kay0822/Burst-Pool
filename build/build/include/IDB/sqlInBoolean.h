
namespace IDB {
 class sqlInBoolean: public Where {
  private:
   std::string col;
   std::vector<bool> values;

  public:
   sqlInBoolean(std::string init_col, std::vector<bool> *init_values);
   sqlInBoolean(std::string init_col, std::list<bool> *init_values);
   std::string toString();


    unsigned int bind(sql::PreparedStatement *pstmt, unsigned int bind_offset);

 };
}

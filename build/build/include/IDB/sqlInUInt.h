
namespace IDB {
 class sqlInUInt: public Where {
  private:
   std::string col;
   std::vector<unsigned long int> values;

  public:
   sqlInUInt(std::string init_col, std::vector<unsigned long int> *init_values);
   sqlInUInt(std::string init_col, std::list<unsigned long int> *init_values);
   std::string toString();


    unsigned int bind(sql::PreparedStatement *pstmt, unsigned int bind_offset);

 };
}

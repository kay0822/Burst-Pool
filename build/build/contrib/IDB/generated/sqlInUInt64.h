
namespace IDB {
 class sqlInUInt64: public Where {
  private:
   std::string col;
   std::vector<unsigned long long int> values;

  public:
   sqlInUInt64(std::string init_col, std::vector<unsigned long long int> *init_values);
   sqlInUInt64(std::string init_col, std::list<unsigned long long int> *init_values);
   std::string toString();


    unsigned int bind(sql::PreparedStatement *pstmt, unsigned int bind_offset);

 };
}

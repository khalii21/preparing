int main()
{
  struct Book
  {
    const char * title;
    const char * author;
  }

  struct Lib
  {
    size_t books;
    const Book * const * lib;
    const size_t * counts;
    const size_t * stocks;
  }

  const Book ** same_author(size_t& out, const Lib & db, const Book* book)
  {
  out = 0;
  const Book ** res = nullptr;
    for (size_t i = 0; i < db.books; i++)
    {
      if (book->author == db.lib[i]->author)
      {
        out++;
      }
    }
  if (out == 0)
  {
    return res;
  }
  res = new const Book *[out];
  size_t index = 0;
  for (size_t i = 0; i < db.books; i++)
    {
      if (book->author == db.lib[i]->author)
      {
        res[index++] = db.lib[i];
      }
    }
  return res;
  }
}


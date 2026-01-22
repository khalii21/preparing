#include <iostream>

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

  const Book ** same_author(size_t& out, const Lib * libs, size_t l, const Book* book)
  {
    out = 0;
    const Book ** res = nullptr;
    for (size_t i = 0; i < l; i++)
    {
      for (size_t j = 0; j < libs[i].books; j++)
      {
        if (libs[i].lib[j]->author == book->author)
        {
          out++;
        }
      }
    }
    if (out == 0)
    {
      return res;
    }
    res = new const Book *[out];
    size_t index = 0;
    for (size_t i = 0; i < l; i++)
    {
      for (size_t j = 0; j < libs[i].books; j++)
      {
        if (libs[i].lib[j]->author == book->author)
        {
          res[index++] = libs[i].lib[j];
        }
      }
    }
    return res;
  }

  const Book ** same_author(size_t& out, const Lib & db, const Book* const* match, size_t b)
  {
    out = 0;
    const Book ** res = nullptr;
    for (size_t i = 0; i < db.books; i++)
    {
      for (size_t j = 0; j < b; j++)
      {
        if (db.lib[i]->author == match[j]->author)
        {
          out++;
          break;
        }
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
      for (size_t j = 0; j < b; j++)
      {
        if (db.lib[i]->author == match[j]->author)
        {
          res[index++] = db.lib[i];
          break;
        }
      }
    }
    return res;
  }

  const Book ** same_author(size_t& out, const Lib * libs, size_t l, const Book* const* match, size_t b)
  {
    out = 0;
    const Book ** res = nullptr;
    for (size_t i = 0; i < l; i++)
    {
      for (size_t j = 0; j < libs[i].books; j++)
      {
        for (size_t k = 0; k < b; k++)
        {
          if (libs[i].lib[j]->author == match[k]->author)
          {
            out++;
            break;
          }
        }
      }
    }
    if (out == 0)
    {
      return res;
    }
    res = new const Book *[out];
    size_t index = 0;
    for (size_t i = 0; i < l; i++)
    {
      for (size_t j = 0; j < libs[i].books; j++)
      {
        for (size_t k = 0; k < b; k++)
        {
          if (libs[i].lib[j]->author == match[k]->author)
          {
            res[index++] = libs[i].lib[j];
            break;
          }
        }
      }
    }
    return res;
  }

  size_t space_after_out(const Lib & db, const Book* book)
  {
    size_t res = 0;
    for (size_t i = 0; i < db.books; i++)
    {
      if (book->author == db.lib[i]->author)
      {
        res += db.stocks[i];
      }
    }
    return res;
  }

  size_t space_after_out(const Lib * libs, size_t l, const Book* book)
  {
    size_t res = 0;
    for (size_t i = 0; i < l; i++)
    {
      for (size_t j = 0; j < libs[i].books; j++)
      {
        if (book->author == libs[i].lib[j]->author)
        {
          res += libs[i].stocks[j];
        }
      }
    }
    return res;
  }

  size_t space_after_out(const Lib & db, const Book* const* match, size_t b)
  {
    size_t res = 0;
    for (size_t i = 0; i < db.books; i++)
    {
      for (size_t j = 0; j < b; j++)
      {
        if (db.lib[i]->author == match[j]->author)
        {
          res += db.stocks[i];
          break;
        }
      }
    }
    return res;
  }

  size_t space_after_out(const Lib * libs, size_t l, const Book* const* match, size_t b)
  {
    size_t res = 0;
    for (size_t i = 0; i < l; i++)
    {
      for (size_t j = 0; j < libs[i].books; j++)
      {
        for (size_t k = 0; k < b; k++)
        {
          if (libs[i].lib[j]->author == match[k]->author)
          {
            res += libs[i].stocks[j];
            break;
          }
        }
      }
    }
    return res;
  }

  size_t out_list(const Book *** to_out, const size_t ** out_each, const Lib & db, const Book* book)
  {
    size_t res = 0;
    *to_out = nullptr;
    *out_each = nullptr;
    for (size_t i = 0; i < db.books; i++)
    {
      if (db.lib[i]->author == book->author)
      {
        res++;
      }
    }
    if (res == 0)
    {
      return res;
    }
    *to_out = new const Book *[res];
    *out_each = new size_t [res];
    size_t index = 0;
    for (size_t i = 0; i < db.books; i++)
    {
      if (db.lib[i]->author == book->author)
      {
        (*to_out)[index] = db.lib[i];
        (*out_each)[index] = db.stocks[i];
        index++;
      }
    }
    return res;
  }
}


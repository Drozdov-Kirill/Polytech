inside(array, size, rectangle); // как должно вызываться

int inside(const Shape *array, int size, const Shape &rect)
{
  if (array == nullptr)
  {
    throw std::invalid_argument("Pointer is nullptr.");
  }
  else if (rect.kind != 1)
  {
    throw std::invalid_argument("The checked shape of the wrong type.");
  }

  int count = 0;
  for (int i = 0; i < size; i++)
  {
    if (array[i].kind == 0)
    {
      if (((array[i].data.c.cx - array[i].data.c.rad) >= (rect.data.r.x))
          && ((array[i].data.c.cx + array[i].data.c.rad) <= (rect.data.r.x + rect.data.r.w))
          && ((array[i].data.c.cy - array[i].data.c.rad) >= (rect.data.r.y))
          && ((array[i].data.c.cy + array[i].data.c.rad) <= (rect.data.r.y + rect.data.r.h))
      )
      {
        ++count;
      }
    }
  }
  return count;
}

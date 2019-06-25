inside(x, y, shapes, size); // как нужно вызывать


bool inside(int coordX, int coordY, const Shape *array, int size)
{
  if (array == nullptr)
  {
    throw std::invalid_argument("Array is nullptr.");
  }

  for (int i = 0; i < size; i++)
  {
    if (array[i].Kind == 0) // Circle
    {
      if (   ((array[i].Data.c.cx + array[i].Data.c.rad) >= coordX)
          && ((array[i].Data.c.cy + array[i].Data.c.rad) >= coordY)
          && ((array[i].Data.c.cy - array[i].Data.c.rad) <= coordY)
          && ((array[i].Data.c.cx - array[i].Data.c.rad) <= coordX))
      {
        return true;
      }
    }
    else if (array[i].Kind == 1) // Rectangle
    {
      if (   ((array[i].Data.r.x + array[i].Data.r.w) >= coordX)
          && ((array[i].Data.r.y + array[i].Data.r.h) >= coordY)
          && (array[i].Data.r.y <= coordY)
          && (array[i].Data.r.x <= coordX))
      {
        return true;
      }
    }
  }
  return false;
}

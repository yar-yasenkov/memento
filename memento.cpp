internal interface IOriginator
  {
    Memento GetMemento();
    void SetMemento(Memento memento);
  }

class Player: IOriginator
  {    
    private int _helth;           

    public Player()
    {
      _helth = 100;      
    }
    
    public void GetHurt(int hurt)
    {
      _helth -= hurt;     
    }

    public void GetCure(int cure)
    {
      _helth += cure;      
    }

    public void PrintPulse()
    {
      if(_helth > 70)
        Console.WriteLine("Green");

      if(_helth <= 70 && _helth > 40)
        Console.WriteLine("Yellow");

      if (_helth <= 40)
        Console.WriteLine("Red");
    }

    public void SetMemento(Memento memento)
    {
      _helth = memento.GetState();
    }

    public Memento GetMemento()
    {
      return new Memento(_helth);
    }
  }
  
  internal class Memento
  {
    private int _helth;

    public Memento(int helth)
    {
      _helth = helth;
    }

    public int GetState()
    {
      return _helth;
    }
  }
  
  class GameUtils
  {
    private Memento _memento;

    public void SaveState(IOriginator originator)
    {
      if (originator == null)
        throw new ArgumentNullException("originator is null");
      
      _memento = originator.GetMemento();

      Console.WriteLine("Save state");
    }

    public void LoadState(IOriginator originator)
    {
      if (originator == null)
        throw new ArgumentNullException("originator is null");
      if (_memento == null)
        throw new ArgumentNullException("memento is null");
      
      originator.SetMemento(_memento);

      Console.WriteLine("Load State");
    }
  }

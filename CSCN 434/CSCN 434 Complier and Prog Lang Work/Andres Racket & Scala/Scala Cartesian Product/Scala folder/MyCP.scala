object myCP {
    def main(args:Array[String])
    {
        val lista = List(101, 102, 103)
        val listb = List(104, 105, 106)
        val listc = List(107, 108, 109)

        val cartesian = lista.map( (x: Int) => (listb.map ( (y:Int) => (listc.map( (z:Int) => (x,y,z))))))

        cartesian.foreach(x => (x.foreach(y => (y.foreach {println}))))
    

    }
}

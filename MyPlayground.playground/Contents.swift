var numbers = [20, 19, 7, 12]
numbers.map({ (number: Int) -> Int in
    let result = 3 * number
    
    if number % 2 != 0{
        return 0}
    return result
})

let sortedNumbers = numbers.sorted { $0 > $1 }
print(sortedNumbers)
class NamedShape {
    var numberOfSides: Int = 0
    var name: String
    
    init(name: String) {
        self.name = name
    }
    
    func simpleDescription() -> String {
        return "A shape with \(numberOfSides) sides."
    }
}
class Circle:NamedShape{
    var radius: Double
    init(radius: Double, name: String){
        self.radius = radius
        super.init(name:name)
    }
    func area()->Double{
       return 3.14 * radius * radius
    }
    override func simpleDescription() -> String {
        return "A circle with radius of length\(radius)"
    }
}

let testCircle = Circle(radius: 3.2, name: "SuperCircle")
testCircle.area()
testCircle.simpleDescription()

enum Rand: Int {
    case ace = 1
    case two, three, four, five, six, seven, eight, nine, ten
    case jack, queen, king
    func simpleDescription() -> String {
        switch self {
        case .ace:
            return "ace"
        case .jack:
            return "jack"
        case .queen:
            return "queen"
        case .king:
            return "king"
        default:
            return String(self.rawValue)
        }
    }
}
let ace = Rand.ten


let aceRawValue = ace.simpleDescription()

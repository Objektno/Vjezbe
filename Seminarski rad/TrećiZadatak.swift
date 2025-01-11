import Foundation

var brojevi: [Int] = [1, 2, 3, 4, 5]


brojevi.append(6)


print("Elementi niza:")
for broj in brojevi {
    print(broj)
}


if let prviElement = brojevi.first {
    print("Prvi element niza je: \(prviElement)")
}

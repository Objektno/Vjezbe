import Foundation

class Automobil {
    var marka: String
    var model: String
    var godina: Int

    init(marka: String, model: String, godina: Int) {
        self.marka = marka
        self.model = model
        self.godina = godina
    }

    func ispisPodataka() {
        print("Automobil: \(marka) \(model), godina: \(godina)")
    }
}

let auto = Automobil(marka: "Tesla", model: "Model S", godina: 2022)
auto.ispisPodataka()

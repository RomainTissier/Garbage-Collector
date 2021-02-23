#[derive(Debug, PartialEq)]
pub struct Info {
    pub i: u64,
    pub j: u64,
}

pub type InfoList = Vec<Info>;

pub trait InfoListMethod {
    fn get_from_i(&self, i: u64) -> Info;
}

impl InfoListMethod for InfoList {
    fn get_from_i(&self, i: u64) -> Info {
        let res = self.iter().find(|&e| (e.i == i)).unwrap();
        Info { i: res.i, j: res.j }
    }
}

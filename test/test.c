
#include "describe.h"
#include "rot13.h"

int main(int argc, char **argv) {

  describe("rot13", {
    it("should rotate strings inline", {
      char hello[] = "hello";
      rot13(hello);
      assert_str_equal("uryyb", hello);
      rot13(hello);
      assert_str_equal("hello", hello);
    });
    it("should return the rotated string", {
      char hello[] = "hello";
      assert_str_equal("uryyb", rot13(hello));
      assert_str_equal("hello", rot13(hello));
    });
    it("should not rotate numbers", {
      char numbers[] = "123456789";
      assert_str_equal("123456789", rot13(numbers));
    });
    it("should handle unicode, but not rotate it", {
      char unicode[] = "åaçcƒf";
      assert_str_equal("ånçpƒs", rot13(unicode));
    });
    it("should rotate uppercase strings", {
      char hello[] = "HELLO";
      assert_str_equal("URYYB", rot13(hello));
    });
  });

  return assert_failures();
}

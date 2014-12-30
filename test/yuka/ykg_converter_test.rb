require_relative '../../lib/yuka/ykg_converter'
require_relative '../test_helper'

# Unit tests for YkgConverter
class YkgConverterTest < Test::Unit::TestCase
  def test_encoding_and_decoding
    test_regions = [
      { x: 0, y: 0, width: 641, height: 720 },
      { x: 330, y: 431, width: 123, height: 234 }]

    data = TestHelper.get_test_file('reimu_transparent.png')
    data, regions = YkgConverter.decode(YkgConverter.encode(data, test_regions))

    assert_equal('PNG', data[1..3])
    assert_equal('IEND', data[-8..-5])
    assert_equal(test_regions, regions)
  end
end